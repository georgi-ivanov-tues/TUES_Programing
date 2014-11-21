package org.elsysbg.courses.ip.sockets.crud.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class CrudOperationsServer {

	private int port;

	private boolean isRunning;

	public CrudOperationsServer(int port) {
		this.port = port;
	}

	public void start() throws IOException {
		if (isRunning) {
			System.out.println("The server is already running");
			return;
		}

		isRunning = true;
		try (ServerSocket serverSocket = new ServerSocket(port)) {
			System.out.println(String.format("Started server on port %d", port));
			while (isRunning) {
				try (Socket clientSocket = serverSocket.accept()) {
					System.out.println(String.format("Accepted connection from client: %s", clientSocket.toString()));

					InputStream inStream = clientSocket.getInputStream();
					OutputStream outStream = clientSocket.getOutputStream();

					try (BufferedReader in = new BufferedReader(new InputStreamReader(inStream));
							PrintWriter out = new PrintWriter(outStream, true);) {
						String s;
						while ((s = in.readLine()) != null) {
							Action action = ActionFactory.create(s);
							if (action != null) {
								action.execute(out);
							} else {
								out.println("Unknown action. Try with create|read|update|delete");
							}
						}
					}
				}
			}
		}
	}

	public void stop() {
		isRunning = false;
	}

}
