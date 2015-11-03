CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g
PERF_stat = cycles,instructions,cache-misses

EXEC = iterative_destroy iterative_floyd recursive
all: $(EXEC)

iterative_destroy: iterative.c
	$(CC) $(CFLAGS_common) -DDESTROY -o $@ $<
	
iterative_floyd: iterative.c
	$(CC) $(CFLAGS_common) -DFLOYD -o $@ $<

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $<

perf-stat:
	@sudo sh -c "echo 0 > /proc/sys/kernel/kptr_restrict"
	@sudo sh -c "echo 1 > /proc/sys/vm/drop_caches"
	perf stat -r 100 -e $(PERF_stat) ./iterative_floyd >> log_floyd.txt
	perf stat -r 100 -e $(PERF_stat) ./iterative_destroy >> log_des.txt
clean:
	$(RM) $(EXEC) *.o perf.*
