counter=0
for i in `seq 1 10`;
do
    exec ./a.out &
    counter=$counter+1
done
