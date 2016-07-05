PRJ=$1

if [ -n "$PRJ" ]; then
   PRJ=t1
fi

../stlcs -C c ${PRJ}.ihx <run.cmd


   
