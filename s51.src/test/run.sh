PRJ=$1

if [ -z "$PRJ" ]; then
   PRJ=t1
fi

../s51 -t517 -C conf.cmd -Z6666 -S in=/dev/null,out=${PRJ}.out -G ${PRJ}.ihx 

cat ${PRJ}.out
