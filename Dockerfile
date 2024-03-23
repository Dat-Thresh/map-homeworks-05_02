FROM ubuntu:latest
LABEL hw_05_02 v1

WORKDIR /cppm-homeworks_05_02/
COPY cppm-homeworks_05_02.cpp .
RUN apt-get update
RUN apt -y install g++ nano
RUN g++ cppm-homeworks_05_02.cpp -o task
CMD ["./task"]

