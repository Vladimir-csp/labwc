#include "labwc.h"

void
interactive_begin(struct view *view, enum cursor_mode mode, uint32_t edges)
{
	/*
	 * This function sets up an interactive move or resize operation, where
	 * the compositor stops propegating pointer events to clients and
	 * instead consumes them itself, to move or resize windows.
	 */
	struct server *server = view->server;
	server->grabbed_view = view;
	server->cursor_mode = mode;

	/* Remember view and cursor positions at start of move/resize */
	server->grab_x = server->cursor->x;
	server->grab_y = server->cursor->y;
	struct wlr_box box = {
		.x = view->x, .y = view->y, .width = view->w, .height = view->h
	};
	memcpy(&server->grab_box, &box, sizeof(struct wlr_box));
	server->resize_edges = edges;
}
