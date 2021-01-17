open Format
let sum_multiples a =
    let sum = ref 0 in
    for i = 0 to (a - 1) do
        if (i mod 3) == 0 || (i mod 5) == 0 then sum := !sum + i;
    done;
    !sum;;

printf ("Sum of the multiples of 3 and 5 from 0 to 10: %d\n") (sum_multiples 10);;
printf ("Sum of the multiples of 3 and 5 from 0 to 1000: %d\n") (sum_multiples 1000);;
