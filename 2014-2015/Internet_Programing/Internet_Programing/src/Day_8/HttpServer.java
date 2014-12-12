package Day_8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;

public class HttpServer {

	private static final int PORT = 4444;

	public static void main(String[] args) throws IOException {

		boolean closing = false;
		// create socket
		try (ServerSocket serverSocket = new ServerSocket(PORT)) {
			System.out.println("Started server on port " + PORT);

			// repeatedly wait for connections, and process
			while (!closing) {

				// a "blocking" call which waits until a connection is requested
				try (Socket clientSocket = serverSocket.accept()) {
					System.out.println("Accepted connection from client: "
							+ clientSocket);

					// open up IO streams
					InputStream inStream = clientSocket.getInputStream();
					OutputStream outStream = clientSocket.getOutputStream();

					try (
							BufferedReader in = new BufferedReader(new InputStreamReader(inStream));
							PrintWriter out = new PrintWriter(outStream, true);
							) {
						String s;
						List<String> allLines = new LinkedList<String>();
						while(true){
							s = in.readLine();
							if(s.equals("")) break;
							allLines.add(s);
						}
						RequestParser rq = new RequestParser();
						Request r = rq.parse(allLines);
						Response response = new Response();
						response.response(out, r);
					}
				}
			}
		}
	}
}