# Console Tetris
A console tetris, KPI course work 2021-2022

Created by KPI TV-12 students:
- Kuruch Ivan @JPlay42
- Neresnytsya Oleh: @clientforgit
- Pylypchuk Mykola @Nick4uogl
- Kostyanov Pavlo @Sw1ft0

Commit rules:
- One of assigned coders unassigns all other ones, sets label `in progress` and works on issue. After commit, he removes the label.
- If you work on issue, tag it in your commit: `Add a class #12345`

How to build and run
- Option 1: build using build.sh script and run `bin/console-tetris`. Ensure that your system has libncurses-dev to compile this app.
- Option 2: build using CMake and run `cmake-build-debug/console-tetris`. Ensure that your system has libncurses-dev to compile this app.
- Option 3: build using Docker. Enter these commands in your system:
```
git clone https://github.com/JPlay42/console-tetris.git
cd console-tetris
docker build -t image .
docker run -it image
```
