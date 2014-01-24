# Makefile

.PHONY: clean

clean:
	find -type d -regex .*chapter[0-9]+/.* | sort | xargs -i{} make -C {} clean
