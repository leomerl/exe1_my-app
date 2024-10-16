FROM gcc:latest AS builder

WORKDIR /app

COPY hello_server.c .

RUN gcc -o hello_server hello_server.c


FROM debian:latest

WORKDIR /app

COPY --from=builder /app/hello_server .

EXPOSE 8080

CMD ["./hello_server"]

