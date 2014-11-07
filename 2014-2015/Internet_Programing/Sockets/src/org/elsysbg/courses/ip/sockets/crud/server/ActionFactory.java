package org.elsysbg.courses.ip.sockets.crud.server;

public class ActionFactory {

	public static Action create(String action) {
		if ("read".equals(action)) {
			return new ReadAction();
		}

		if ("create".equals(action)) {
			return new CreateAction();
		}

		if ("delete".equals(action)) {
			return new DeleteAction();
		}

		if ("update".equals(action)) {
			return new UpdateAction();
		}

		return null;
	}
}
