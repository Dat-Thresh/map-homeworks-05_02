FROM ubuntu:latest
LABEL hw_05_02 v1

WORKDIR /cppm-homeworks_05_02/
COPY cppm-homeworks_05_02.cpp .
RUN apt-get update
RUN apt -y install g++ nano clang
RUN g++ cppm-homeworks_05_02.cpp -o task
RUN clang++ cppm-homeworks_05_02.cpp -o task_clang.exe
CMD ["./task"]
CMD ["./task_clang.exe"]

