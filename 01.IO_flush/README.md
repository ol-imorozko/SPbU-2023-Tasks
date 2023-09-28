# Usage

`./iterate_args.bash`

# Cleanup

`./cleanup.bash`

# Results

- Experiment: -w : redirecting to file

Output: The file ("output_w.txt") contains only STDERR without newline.

- Experiment: -n : using newlines

Output: "STDOUT" and "STDERR" are printed to the console with newlines.

- Experiment: -w -n : using newlines, redirecting to file

Output: The file ("output_wn.txt") contains only STDERR with newline.

- Experiment: -f : using fflush

Output: "STDOUT" and "STDERR" are printed to the console without newlines.

- Experiment: -w -f : using fflush, redirecting to file

Output: The file ("output_wf.txt") contains only STDERR without newline.

- Experiment: -n -f : using fflush, using newlines

Output: "STDOUT" and "STDERR" are printed to the console with newlines.

- Experiment: -w -n -f : using fflush, using newlines, redirecting to file

Output: The file ("output_wnf.txt") contains only STDERR with newline.
