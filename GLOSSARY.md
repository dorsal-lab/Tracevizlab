# Glossary

## Atomic operation[^2]
An atomic operation has the characteristic of being indivisible, which implies that intermediate values or intermediate states are invisible to concurrent operations. Atomic operations usually require support from the hardware or the operating system, and great care must be taken by the developer to guarantee atomicity. For instance, on x86 architectures, a mov instruction isn’t guaranteed to be atomic unless its operands are cache-aligned. Consider the case where one of the operands is stored across two pages: the mov instruction will require access to different pages (and potentially cause virtual address translations), making the operation divisible and non-atomic, as an intermediate unstable value can be visible if the operand is accessed by another instruction between these steps.
  
## Automatic instrumentation
Automatically adding hooks to a program. This can be achieved by a source to source transformation program, by the compiler, or by a binary instrumentation program. Automatically inserted instrumentation will typically target well-defined specific events such as function or basic block entry and exit, or memory accesses.

## Binary instrumentation
Instrumenting the compiled binary of an application, rather than the source code.

## CTF: Common Trace Format
A compact binary trace format defined by the DiaMon group of the Linux Foundation and supported by several tracing tools such as LTTng and Trace Compass.

## Compute Kernel[^5]
What is invoked by the Host to run on the GPU is called a Kernel. A Kernel is a scalar C program that defines a single thread’s execution. Prior to the threads execution the data it is to operate on is transferred to GPU. The invocation of the kernel function typically has pointers to data areas and scalars such as integers and floats that parameterize the execution. What is different from a normal C function invocation is, of course, that multiple instances of the function are invoked and each is assigned to a an individual GPU thread.

## Conditional tracepoint
A tracepoint for which, when executed, an event is generated only if a certain condition is met. This is useful because checking a condition is typically much faster than writing an event to a file.
 
## Current state
The state of all relevant resources, in the model constructed when reading a trace, at a given point in time. It is obtained by processing all the events with an earlier timestamp, and computing the state of resources accordingly.

## Debugging
Running a program through a debugger. A debugger can control the execution (set breakpoints, stop and resume the execution) and look at the content of memory, including variables and the stack.

## Distributed tracing
Tracing a distributed system. A popular API for distributed tracing is [OpenTelemetry](https://opentelemetry.io/), and many groups will equate distributed tracing to OpenTelemetry like traces.

## Distributed trace
A trace generated on several computers that are part of a distributed system.

## Dynamic tracepoint activation
Tracepoints are often inserted statically but not activated by default. It is then possible to selectively activate tracepoints during the program execution. This can be achieved through a conditional statement on a boolean variable associated with the activation of this tracepoint. Another method is to leave a NOP instruction that can be replaced at runtime by a call to the tracing code.

## Dynamic instrumentation
Instrumentation of a program after it began executing. This is challenging because the program may be currently executing the instructions where a probe needs to be added.

## Dynamic tracepoint
A tracepoint added through dynamic instrumentation. It is also sometimes used by extension to describe tracepoints added by binary instrumentation, after compilation but before starting the execution.

## Event[^2]
An event marks the encounter of a tracepoint at runtime. Depending on the kind of tracing, the event can have a logical meaning, such as a context switch, or can simply represent a location in the code, such as a function entry or exit. It typically has a timestamp, a type and possibly a payload.

## Fast tracepoint
A faster more optimised type of tracepoint, as compared to a regular tracepoint. For instance, in the Linux kernel, kprobe offered regular tracepoints based on traps. Later, fast tracepoints were offered, based on jumps, for inserting tracepoints at locations where some conditions were met (e.g. at 5 bytes instructions on x86).

## Flight recorder mode
Events are initially stored in buffers that may later be flushed to disk or to a network socket. Storing the events to disk is more costly and may result in huge traces. It may be a waste, when the traced program runs fine. In flight recorder mode, the events are written to a circular buffer and older events are overwritten as newer events are written. When a condition arises where there is something of interest in the trace, tracing can be stopped and the content of the flight-recorder mode buffers is saved to disk. For example, if a crash, large latency or other problem is detected in an application, the events stored in the buffer may contain relevant information to understand the condition that led to the problem. This is similar to flight recorders in planes, that stop recording when a plane crashes, and are later retrieved to understand the conditions that led to the crash.

## Jump-based tracepoint
A jump based tracepoint replaces the instructions at the instrumentation location by a jump to the probe instructions. The replaced instructions are executed out of line, after the probe is executed. This is typically much faster (e.g. 5 to 10 times) than a trap-based tracepoint.

## Kernel tracing
Tracing the execution of the operating system kernel. Most operating systems like Linux, Windows or Solaris contain manually instrumented static tracepoints that can be activated dynamically. Since all interactions of processes with the outside world go though system calls, a lot of information about each thread execution can be obtained through a kernel trace.

## Instrumentation
Adding probes to a program to gather data about its execution.

## Live tracing
Displaying the content of a trace while it is being generated, thus getting immediate feedback about a program during its execution.
 
## Logging
Generating entries in a log, writing error or debugging messages to a text file (like printk statements in the Linux kernel sent to the syslog subsystem). Some authors will use the term tracing for OpenTracing traces, and logging for traces and logs. In that case, they will distinguish between structured logs (binary traces) and unstructured logs (printk style text messages).

## Manual instrumentation
Probes or tracepoints inserted manually in the program (source code) by the user.

## Online trace analysis
Analysing a trace while it is still being generated and recorded. There will often still be a latency between the generation of an event and its availability for online analysis. For instance, events may be buffered and become available only when the buffer is full and is flushed to disk.

## OpenTelemetry (formerly OpenTracing, OpenCensus)[^6]
Open Telemetry is a set of standardized vendor-agnostic SDKs, APIs, and tools for ingesting, transforming, and sending data to an Observability back-end (i.e. open-source or commercial vendor). It works by instrumenting each request begin and end, noting the enclosing request identifier.

## Operating System Kernel[^3]
The kernel is a program that constitutes the central core of a computer operating system. It has complete control over everything that occurs in the system. The kernel is the first part of the operating system to load into memory during booting (i.e., system startup), and it remains there for the entire duration of the computer session because its services are required continuously. Thus it is important for it to be as small as possible while still providing all the essential services needed by the other parts of the operating system and by the various application programs.

## Out of line execution
When inserting a breakpoint or tracepoint dynamically, some instructions have to be replaced and must be executed elsewhere, out of line. Care must be taken to compensate if needed the fact that these instructions are executed out of line, at a different address. This is the case for instructions that somehow depend on the instruction pointer, like instructions that use addresses relative to the instruction pointer.
 
## OTF2: Open Trace Format version 2
Defined by a group of researchers working on tracing tools for High Performance Computing. The Score-P measurement infrastructure uses that format.

## Payload[^2]
An event typically holds a payload, which is additional information related to the event. For instance, the payload of a context switch may contain the identifiers of the two tasks involved.

## Performance counters
Hardware performance counters are registers, accessible by programs, that are set by the hardware to provide different metrics. On many platforms, these counters may also generate interrupts. This can be used to generate interrupts every 100000 cache misses, for instance, for statistical profiling purposes.

## Probe[^2]
A probe is a function that is hooked to a tracepoint and is called whenever the tracepoint is encountered at runtime (if enabled). A probe usually performs a custom task and is either implemented by the tracer or by the user. Typically, a probe needs to be as small and fast as possible, to add as little overhead as possible and reduce the perturbation to the system.

## Probe handler
In some systems, a generic probe is inserted by the instrumentation tool. A probe handler can then be specified to be called when the probe is executed. The probe handler can gather data about the execution or verify some properties.

## Profiling
Generating a profile of the execution, for instance the number of times each function is called, the time spent in each function, or the number of cache faults associated with each instruction. A profile can be obtained by tracing (e.g. tracing each function entry to know the number executions). However, it is more common to have a profile generated through sampling, because of the lower overhead. For example, the instruction pointer can be sampled through a periodic interrupt, to have an idea of the functions in which an application spends most of its execution time.

## Ring buffer[^2]
A data structure that serves as a placeholder for events. When an event is recorded at run-time, the tracer’s probe is invoked. The probe records the encountered event by placing it in memory in the ring buffer (producer). At a later time, a consumer can read the contents of the ring buffer and report them to the user. When the data structure is full, the incoming events may either replace the oldest events (in a ring-like fashion) or they may be discarded until some events have been consumed from the buffer.

## Span
The time interval from the start to the end of a request.

## State
State of a relevant resource. The state can be reported directly by trace events (e.g. Begin and End events for function execution, thread running on a CPU core...). The state can also be deduced from a more generic event. For instance, upon a scheduling switch from thread A to thread B, the execution state of thread A may change to Preempted, the execution state of thread B as Running, and the Current Thread state of the affected core changes from A to B. The times at which a new state appears, and is later replaced, is noted and determines the time interval associated to that state value for this resource. 

## State history
Database of the state values over time for the relevant resources in a traced system.
 
## Static tracepoint
Tracepoint inserted in a program at or before compilation time.

## Static instrumentation
Inserting tracepoints in a program, manually or automatically, at or before compilation time.

## Trace[^4]
[A Trace] is a sequence of low-level events. Such events are produced whenever a specific instruction called tracepoint is encountered at runtime and comprises a name, a precise timestamp, and possibly many arguments. The trace data is typically stored in buffers, and then consumed by a program, overwritten, sent over the network or written to a file.

## Trace format
Traces are stored in either textual or binary formats. Textual formats, like JSON and XML, are easy to read without the need for a special tool. However, they are typically much larger and require more CPU time for parsing. Binary formats, like CTF and OTF2, are very compact and require little processing.  

## Trace streaming
Trace generated on a continuous basis and that can be accessed as it is generated. There may be a certain latency between when an event is generated and when it can be accessed. Tracefile rotation, where a trace is generated in small chunks (e.g. numerous files of fixed size), may be considered a crude form of trace streaming.

## Trace viewer
The trace data stored in a file can be in different formats. Some textual formats can be viewed with a simple text editor, while binary formats are difficult to examine without a special tool. A trace viewer can present the trace content in a convenient format for visualisation, allow navigating through the trace timeline, compute statistics and display various graphs.

## Tracefile rotation
Trace files can become extremely large. Some tracers allow to divide the trace generated into multiple fixed size files. This insures that each file is not too large. Moreover, the already generated files can be analyzed while tracing continues in a new file. 

## Tracepoint
Instruction sequence in a program that generates a trace or log entry (event) when executed.

## Tracer
Program or library used to generate a trace during the execution of a program containing tracepoints.

## Tracing[^1]
Tracing is a technique used to understand what goes on in a running software system. The piece of software used for tracing is called a tracer, which is conceptually similar to a tape recorder. When recording, specific instrumentation points placed in the software source code generate events that are saved on a giant tape: a trace file. You can record user application and operating system events at the same time, opening the possibility of resolving a wide range of problems that would otherwise be extremely challenging.
Tracing is often compared to logging. However, tracers and loggers are two different tools, serving two different purposes. Tracers are designed to record much lower-level events that occur much more frequently than log messages, often in the range of thousands per second, with very little execution overhead. Logging is more appropriate for a very high-level analysis of less frequent events: user accesses, exceptional conditions (errors and warnings, for example), database transactions, instant messaging communications, and such. Simply put, logging is one of the many use cases that can be satisfied with tracing.

## Tracing real-time systems
Generating a trace during program execution without significantly affecting the program timing or synchronisation. This typically requires lock free algorithms to generate events in buffers, and flushing buffers asynchronously.

## Trap-based tracepoint
Tracepoint that generates a soft interrupt when encountered (e.g. int3 on x86), typically causing context changes and resulting in non negligible delay.

## User space tracing
Tracing the execution of a program in user space. While some tracers generate a system call upon encountering a tracepoint, others remain in user space (for instance LTTng UST writing the events in a buffer).

[^1]: https://lttng.org/docs/
[^2]: Gebai, M. & Dagenais, M. R. (2018). Survey and analysis of Kernel and userspace tracers on Linux : design, implementation, and overhead. ACM Computing Surveys, 51(2), 26:1-26:33. doi:10.1145/3158644
[^3]: http://www.linfo.org/kernel.html
[^4]: Fournier, Q., Aloise, D., Azhari, S.V., & Tetreault, F. (2021). On Improving Deep Learning Trace Analysis with System Call Arguments. 2021 IEEE/ACM 18th International Conference on Mining Software Repositories (MSR), 120-130.
[^5]: Jamsek, D. A. (2009). Designing and optimizing compute kernels on NVIDIA GPUs. 2009 Asia and South Pacific Design Automation Conference, 224–229. doi:10.1109/ASPDAC.2009.4796484
[^6]: https://opentelemetry.io/docs/concepts/what-is-opentelemetry/