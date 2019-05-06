if [ $1 = "APB" ]; then
    cd APB
    bash run.sh
elif [ $1 = "ATB" ]; then
    cd ATB
    bash shell.sh
elif [ $1 = "AHB" ]; then
    cd AHB
    bash shell.sh
fi
