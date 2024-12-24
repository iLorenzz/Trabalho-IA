FROM alpine:3.19.4

RUN apk update && \
    apk add --no-cache build-base \
    cmake \
    git

WORKDIR /bin/Trabalho-IA

COPY . .

RUN cmake -B build

WORKDIR /bin/Trabalho-IA/build 
RUN cmake .. && make

CMD ["./Trabalho_IA"]




