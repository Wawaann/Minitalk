# Minitalk

**Minitalk** is a project where the goal is to implement a simple communication protocol between a client and a server using UNIX signals. The client sends a message to the server, and the server acknowledges each received bit. The project involves handling signals, bit manipulation, and proper synchronization between processes.

## Project Overview

In this project, we use the following signals:

- `SIGUSR1` to represent a bit value of `0`.
- `SIGUSR2` to represent a bit value of `1`.

The client sends a message to the server by transmitting each character's bits one by one. The server receives the bits, reconstructs the characters, and prints them. After receiving a complete message, the server acknowledges the reception.

## Features

- The client can send a message to the server.
- The server processes the received bits and reconstructs the original message.
- The server sends an acknowledgment signal after receiving each bit.
- Proper error handling is in place, e.g., when the server is unavailable.
- The server gracefully handles client disconnections.

## How the Project Works

The **Minitalk** project implements a communication protocol between a client and a server using UNIX signals. The client sends a message to the server by sending one bit at a time, and the server receives the message, reconstructs it, and acknowledges each received bit.

### Client-Side

On the client side, the message is sent by breaking it down into individual characters. Each character is sent as a sequence of bits, where each bit is transmitted using a signal:
- `SIGUSR1` represents a `0` bit.
- `SIGUSR2` represents a `1` bit.

The client uses `send_sig` to send the signal to the server, based on the bit value it is sending. After each bit is sent, the client waits for the server to acknowledge it before sending the next bit. This is achieved by using `usleep(50)` in a loop until an acknowledgment (`SIGUSR1`) is received from the server, ensuring that the client waits for the server's acknowledgment before proceeding with the next bit.

### Server-Side

The server listens for incoming signals (`SIGUSR1` and `SIGUSR2`) from the client. It uses `handle_signal` to process the received signals and reconstruct the message:
- When `SIGUSR2` is received, the server sets the corresponding bit in a character variable (`acc`).
- Once 8 bits are received (one character), the server prints the character to the console.
- After receiving the full message (indicated by a null character `'\0'`), the server sends an acknowledgment (`SIGUSR1`) to the client and finishes processing.

### Synchronization Between Client and Server

The key challenge of this project is synchronizing the communication between the client and the server. Without proper synchronization, the client might send signals too fast, and the server could miss them or not process them in the correct order.

In the traditional approach, one might consider using `usleep(300)` to create a delay between each signal. However, this method is unreliable because the actual sleep duration depends on the speed of the machine and could vary significantly across different systems. This could lead to synchronization issues where the server might not receive the signal properly, especially on slower machines.

Instead, **Minitalk** uses a more robust method by having the client wait for an explicit acknowledgment from the server after each bit. The server sends a `SIGUSR1` signal after processing each bit, which serves as the acknowledgment. The client only proceeds to send the next bit after receiving this acknowledgment. This ensures that the communication is perfectly synchronized regardless of the machine's speed, as the client does not rely on arbitrary sleep times, but rather on the actual acknowledgment signal from the server.

## Requirements

To compile and run this project, you need:

- A C compiler (e.g., `gcc`).
- A Unix-based system (Linux, macOS, etc.) with access to POSIX signals.

## How to Compile

1. Clone the repository:

    ```bash
    git clone https://github.com/Wawaann/Minitalk.git
    cd Minitalk
    ```

2. Compile the project:

    ```bash
    make
    ```

    This will generate the `server` and `client` executables.

## How to Test

1. Open a terminal and run the server:

    ```bash
    ./server
    ```

    The server will print its process ID (PID) when it starts.

2. In another terminal, run the client and provide the server's PID and the message you want to send:

    ```bash
    ./client [server_pid] "Your message here"
    ```

    Example:

    ```bash
    ./client 12345 "Hello, world!"
    ```

    The client will send each bit of the message to the server, and the server will print the message after receiving it.

## Error Handling

- If the client tries to send a message to an invalid PID or a non-existent process, an error message will be printed.
- If the client disconnects before finishing the message, the server will handle this gracefully and reset its state.

## Additional Information

- The project was validated with a **125%** score.
- The code follows the **Norm** (42 coding style) and is written in the **C** programming language.
