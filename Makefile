build: minlexbfs.cpp revedges.cpp
	g++ minlexbfs.cpp -o minlexbfs
	g++ revedges.cpp -o revedges
run-p1: minlexbfs
	./minlexbfs

run-p4: revedges
	./revedges

clean:
	rm -rf minlexbfs revedges
