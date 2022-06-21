FROM alpine:3.16

RUN apk --no-cache add ncurses-dev cmake make g++ libc-dev linux-headers bash libstdc++ libgcc

RUN ln -sf /app/shapes.conf /shapes.conf
WORKDIR /app
ADD . .

RUN cmake . && make && mv console_tetris bin

CMD ["/app/bin/console_tetris"]
