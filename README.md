# libft-unity

![](https://i.imgur.com/7abjtjL.png)

`libft-unity` is a test framework to test the libft, a C library made for the
first 42 project. It relies on the [unity](http://www.throwtheswitch.org/unity)
testing API.

## Usage

1) Clone this repo.
2) Edit the configuration file. (`libft_unity.config`)
3) ./run.sh

You can run `./run.sh help` to get a list of all the available commands and
options. Below are the main commands you'll eventually need:

```bash
# Will run the tests corresponding to the part1 of the libft project
$> ./run.sh p1

# Will run the tests of part1 and part2 one after the other
$> ./run.sh p1 p2

# Will run the bonus part tests
# A bonus rule must be available in your libft's Makefile
$> ./run.sh bonus

# Will run part1, part2 and bonus tests and invoke make fclean before doing
# any other make command.
$> ./run.sh full --re

# Will run tests for ft_atoi and ft_substr ONLY
$> ./run.sh ft_atoi ft_substr
```

Note that the [unity](http://www.throwtheswitch.org/unity) test API should
be automatically cloned the first time you run the script.

When running a test runner, a logfile will be generated under the `logs/` directory.
It only stores what is printed on `stdout` when you run the `./run.sh` command, but
this way you can keep track of your progress if you want to.

## Troubleshooting

If you run into an issue, please open a new github issue so I can track it
easily. By the way, if your code is not working this is not an issue.
