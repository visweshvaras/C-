#!/usr/bin/env bash
# ==============================================================================
# Script to compile and execute all 39 DIY programs from the lab manual
# ==============================================================================
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
if [ -d "${SCRIPT_DIR}/DIY" ]; then
    DIY_DIR="${SCRIPT_DIR}/DIY"
else
    DIY_DIR="${SCRIPT_DIR}"
fi

echo "================================================================="
echo "   Running All 39 DIY Programs (ECE121 Lab Manual Exercises)    "
echo "================================================================="

TOTAL=0
PASSED=0
FAILED=0

# Loop through week directories
while IFS= read -r -d '' week_dir; do
    folder_name="$(basename "${week_dir}")"
    # Skip non-week folders like .git
    if [[ ! "${folder_name}" =~ ^[0-9]+_ ]]; then
        continue
    fi

    echo ""
    echo "-----------------------------------------------------------------"
    echo "  Folder: ${folder_name}"
    echo "-----------------------------------------------------------------"

    while IFS= read -r -d '' cpp_file; do
        base_name="$(basename "${cpp_file}" .cpp)"
        exe_file="${week_dir}/${base_name}"
        TOTAL=$((TOTAL + 1))

        # Compile if executable does not exist or source is newer
        if [ ! -f "${exe_file}" ] || [ "${cpp_file}" -nt "${exe_file}" ]; then
            echo "Compiling ${base_name}.cpp..."
            g++ -std=c++17 "${cpp_file}" -o "${exe_file}" -pthread
        fi

        echo -n "Executing [${base_name}] ... "
        # Run inside folder with sample input piped
        if (cd "${week_dir}" && echo "hello world cpp" | ./"${base_name}" > /dev/null 2>&1); then
            echo "PASS"
            PASSED=$((PASSED + 1))
        else
            echo "FAIL"
            FAILED=$((FAILED + 1))
        fi
    done < <(find "${week_dir}" -maxdepth 1 -name "*.cpp" -print0 | sort -z)

done < <(find "${DIY_DIR}" -mindepth 1 -maxdepth 1 -type d -print0 | sort -z)

echo ""
echo "================================================================="
echo "   Summary: ${PASSED}/${TOTAL} DIY Programs Executed Successfully! "
echo "================================================================="
