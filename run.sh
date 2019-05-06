if [ $# -eq 0 ]; then
      echo "Invalid argument, use (APT | ATB | AHB)"
      echo "Example: bash run.sh APT"
elif [ $1 = "APB" ]; then
    cd APB
    bash run.sh
elif [ $1 = "ATB" ]; then
    cd ATB
    bash shell.sh
elif [ $1 = "AHB" ]; then
    cd AHB
    bash shell.sh
else
    echo "Invalid argument, use (APT | ATB | AHB)"
    echo "Example: bash run.sh APT"
fi
