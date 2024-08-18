# SeaSHell

SeaSHell is a simple, non-POSIX shell written in C. It's in its early stages, so don't expect too much—it’s mostly just me trying to figure out how C works. The shell is pretty basic, and there’s a lot that could be better, but it can run processes and handle some basic inputs. I’m learning as I go, so please forgive any rough edges!

## Features

- **Basic Functionality**: You can run standard commands, and SeaSHell will try its best to make them work (no promises, though!).
- **Keyboard Shortcuts**: I've managed to get some basic shortcuts like `CTRL+C`, `CTRL+D`, and `CTRL+L` working, so at least there's that.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/SeaSHell.git
   ```
2. Navigate to the SeaSHell directory:
   ```sh
   cd SeaSHell
   ```
3. Compile the shell:
   ```sh
   make
   ```
4. Run SeaSHell:
   ```sh
   ./CSH
   ```

## Usage

It does not have any customization, therefore you can just type the commands you wish.

## Future Plans

- **Alias Support**: If I can figure it out, I’ll add support for aliases and maybe some other customizable features.
- **Config Files**: I’m hoping to eventually support custom configuration files, but let’s see if I can get there.
- **More Built-in Commands**: Right now, SeaSHell only has `cd` as a built-in command, but I’m planning to add more to make it more functional.
