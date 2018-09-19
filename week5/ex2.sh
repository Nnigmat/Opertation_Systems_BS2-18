name_of_file="inp_for_ex2.txt"
while true; do
    if ! ln lock inp_for_ex2.lock
    then
        sleep 1
    else
        file=$(<${name_of_file})
        last_digit=${file:${#str} - 1}
        last_digit=$(($last_digit+1))
        echo $file$last_digit > $name_of_file
        rm inp_for_ex2.lock
        break
    fi
done
