FROM gcc:latest

WORKDIR /app

COPY . .

RUN gcc -o hello hello.c

ENTRYPOINT ./hello


