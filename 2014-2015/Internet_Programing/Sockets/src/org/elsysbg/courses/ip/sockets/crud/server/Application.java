package org.elsysbg.courses.ip.sockets.crud.server;

import java.io.IOException;

public class Application {

	public static void main(String[] args) throws IOException, InterruptedException {
		CrudOperationsServer crudOperationsServer = new CrudOperationsServer(4444);
		crudOperationsServer.start();
	}
}
