FROM gcc:latest AS builder
WORKDIR /app
COPY hello.c .
RUN gcc -o hello hello.c

FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/hello .
CMD ["./hello"]
