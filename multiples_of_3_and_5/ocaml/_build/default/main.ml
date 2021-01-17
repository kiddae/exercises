let sum_multiples a =
    let sum = ref 0 in
    for i = 0 to (a - 1) do
        if (i mod 3) == 0 || (i mod 5) == 0 then sum := !sum + i;
    done;
    !sum;;

print_string "What limit? "
let a = read_int ();;
Printf.printf ("Sum of the multiples of 3 and 5 from 0 to %d: %d\n") a (sum_multiples a);;
