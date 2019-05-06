if [ $# -eq 0 ]; then
    echo "Invalid argument, use (APB | ATB | AHB)"
    echo "Example: bash run.sh APB"
elif [ $1 = "APB" ]; then
    cd APB
    bash run.sh
elif [ $1 = "ATB" ]; then
    cd ATB
    bash run.sh
elif [ $1 = "AHB" ]; then
    cd AHB
    bash run.sh
else
    echo "Invalid argument, use (APB | ATB | AHB)"
    echo "Example: bash run.sh APB"
fi
