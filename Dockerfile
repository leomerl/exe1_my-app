FROM gcc:latest AS builder
WORKDIR /app
COPY run_hello.c .
RUN gcc -o hello run_hello.c

FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/hello .
CMD ["./hello"]
