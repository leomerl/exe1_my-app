FROM gcc:latest AS builder

WORKDIR /src

COPY server_hello.c .

RUN gcc -o server_hello server_hello.c


FROM debian:latest

WORKDIR /app

COPY --from=builder /src/server_hello .

EXPOSE 8080

CMD ["./server_hello"]

