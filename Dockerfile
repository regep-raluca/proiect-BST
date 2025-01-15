FROM gcc:latest
RUN mkdir -p /usr/src/myapp
WORKDIR /usr/src/myapp
COPY proiectBST.c .
RUN gcc -o proiectBST proiectBST.c 
CMD ["./proiectBST"]
