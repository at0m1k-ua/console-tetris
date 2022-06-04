FROM alpine:3.16

RUN apk --no-cache add ncurses-dev cmake clang clang-dev make gcc g++ libc-dev linux-headers bash libstdc++ libgcc

RUN ln -sf /app/shapes.conf /shapes.conf
WORKDIR /app
ADD . .

RUN cmake . && make
RUN mkdir bin && ./build.sh

CMD ["/app/bin/console_tetris"]
