FROM alpine:3.19.4 AS build

RUN apk update && \
    apk add --no-cache build-base \
    cmake \
    git

WORKDIR /home
ADD git@github.com:iLorenzz/Trabalho-IA.git .

RUN cmake -B build

WORKDIR /home/build 
RUN cmake .. && make

CMD ["./Trabalho_IA"]




