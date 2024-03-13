#undef LTTNG_UST_TRACEPOINT_PROVIDER
#define LTTNG_UST_TRACEPOINT_PROVIDER ring

#undef LTTNG_UST_TRACEPOINT_INCLUDE
#define LTTNG_UST_TRACEPOINT_INCLUDE "./ring_tp.h"

#if !defined(_RING_TP_H) || defined(LTTNG_UST_TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>

/* An event */
LTTNG_UST_TRACEPOINT_EVENT(
    /* Tracepoint provider name */
    ring,
    /* Tracepoint class name */
    init,
    /* Input arguments */
    TP_ARGS(
        int, worker_id
    ),
    /* Output event fields */
    TP_FIELDS(
        ctf_integer(int, worker_id, worker_id)
    )
)

LTTNG_UST_TRACEPOINT_EVENT(
    ring,
    recv_exit,
    TP_ARGS(
        int, worker_id
    ),
    TP_FIELDS(
        ctf_integer(int, source, worker_id)
    )
)

LTTNG_UST_TRACEPOINT_EVENT(
    ring,
    send_entry,
    TP_ARGS(
        int, worker_id
    ),
    TP_FIELDS(
        ctf_integer(int, dest, worker_id)
    )
)

/* The tracepoint class */
LTTNG_UST_TRACEPOINT_EVENT_CLASS(
    /* Tracepoint provider name */
    ring,
    /* Tracepoint class name */
    no_field,
    /* Input arguments */
    TP_ARGS(

    ),
    /* Output event fields */
    TP_FIELDS(

    )
)

/* Trace point instance of the no_field class */
LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    ring,
    no_field,
    ring,
    recv_entry,
    TP_ARGS(

    )
)

LTTNG_UST_TRACEPOINT_EVENT_INSTANCE(
    ring,
    no_field,
    ring,
    send_exit,
    TP_ARGS(

    )
)

#endif /* _RING_TP_H */

#include <lttng/tracepoint-event.h>
