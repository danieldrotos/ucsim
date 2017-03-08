VERS="5 6"

TESTS=$(cat st_list.txt)

rm -f *.csv
for t in $TESTS; do
    for v in $VERS; do
	make -f st${t}.mk
	./st.sh -$v $t
    done
done

cat st*[56].csv >st.csv
