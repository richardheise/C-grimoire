#!/bin/bash

for test_in in tests/*.in; do
    test_out="${test_in%.in}.out"
    test_name=$(basename "$test_in" .in)
    
    # Run the calculator with the input file and capture the output
    output=$(./calculator < "$test_in")
    
    # Compare the output with the expected output
    if diff -w <(echo "$output") "$test_out" > /dev/null; then
        echo "Test $test_name: PASSED"
    else
        echo "Test $test_name: FAILED"
        echo "Expected:"
        cat "$test_out"
        echo "Got:"
        echo "$output"
    fi
done
