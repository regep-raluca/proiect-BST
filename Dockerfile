FROM gcc:latest
WORKDIR /usr/src/myapp
COPY proiectBST.c .
RUN gcc -o proiectBST proiectBST.c 
CMD ["./proiectBST"]