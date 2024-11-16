if [ ! -d "build" ]; then
  mkdir build
fi

cd build || return

cmake .. && make && ./Trabalho_IA
