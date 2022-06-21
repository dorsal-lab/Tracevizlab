# Glossary
## Tracing[^1]
Tracing is a technique used to understand what goes on in a running software system. The piece of software used for tracing is called a tracer, which is conceptually similar to a tape recorder. When recording, specific instrumentation points placed in the software source code generate events that are saved on a giant tape: a trace file. You can record user application and operating system events at the same time, opening the possibility of resolving a wide range of problems that would otherwise be extremely challenging.
Tracing is often compared to logging. However, tracers and loggers are two different tools, serving two different purposes. Tracers are designed to record much lower-level events that occur much more frequently than log messages, often in the range of thousands per second, with very little execution overhead. Logging is more appropriate for a very high-level analysis of less frequent events: user accesses, exceptional conditions (errors and warnings, for example), database transactions, instant messaging communications, and such. Simply put, logging is one of the many use cases that can be satisfied with tracing.

## Trace[^4]
[A Trace] is a sequence of low-level events. Such events are produced whenever a specific instruction called tracepoint is encountered at runtime and comprises a name, a precise timestamp, and possibly many arguments.

## Tracepoint[^2]
A tracepoint is a statement placed directly in the code of an application that provides a hook to invoke a probe. A tracepoint generally provides a way in which it can be enabled or disabled dynamically.

## Event[^2]
An event marks the encounter of a tracepoint at runtime. Depending on the kind of tracing, the event can have a logical meaning, such as a context switch, or can simply represent a location in the code, such as a function entry or exit. An event is punctual and has no duration, and is usually annotated with a timestamp.

## Payload[^2]
An event typically holds a payload, which is additional information related to the event. For instance, the payload of a context switch may contain the identifiers of the two tasks involved.

## Probe[^2]
A probe is a function that is hooked to a tracepoint and is called whenever the tracepoint is encountered at runtime (if enabled). A probe usually performs a custom task and is either implemented by the tracer or by the user. Typically, a probe needs to be as small and fast as possible, to add as little overhead as possible and reduce the perturbation to the system.

## Operating System Kernel[^3]
The kernel is a program that constitutes the central core of a computer operating system. It has complete control over everything that occurs in the system. The kernel is the first part of the operating system to load into memory during booting (i.e., system startup), and it remains there for the entire duration of the computer session because its services are required continuously. Thus it is important for it to be as small as possible while still providing all the essential services needed by the other parts of the operating system and by the various application programs.

## Compute Kernel[^5]
What is invoked by the Host to run on the GPU is called a Kernel. A Kernel is a scalar C program that defines a single thread’s execution. Prior to the threads execution the data it is to operate on is transferred to GPU. The invocation of the kernel function typically has pointers to data areas and scalars such as integers and floats that parameterize the execution. What is different from a normal C function invocation is, of course, that multiple instances of the function are invoked and each is assigned to a an individual GPU thread.

## Ring buffer[^2]
A data structure that serves as a placeholder for events. When an event is recorded at run-time, the tracer’s probe is invoked. The probe records the encountered event by placing it in memory in the ring buffer (producer). At a later time, a consumer can read the contents of the ring buffer and report them to the user. When the data structure is full, the incoming events may either replace the oldest events (in a ring-like fashion) or they may be discarded until some events have been consumed from the buffer.

## Atomic operation[^2]
An atomic operation has the characteristic of being indivisible, which implies that intermediate values or intermediate states are invisible to concurrent operations. Atomic operations usually require support from the hardware or the operating system, and great care must be taken by the developer to guarantee atomicity. For instance, on x86 architectures, a mov instruction isn’t guaranteed to be atomic unless its operands are cache-aligned. Consider the case where one of the operands is stored across two pages: the mov instruction will require access to different pages (and potentially cause virtual address translations), making the operation divisible and non-atomic, as an intermediate unstable value can be visible if the operand is accessed by another instruction between these steps.


[^1]: https://lttng.org/docs/
[^2]: Gebai, M. & Dagenais, M. R. (2018). Survey and analysis of Kernel and userspace tracers on Linux : design, implementation, and overhead. ACM Computing Surveys, 51(2), 26:1-26:33. doi:10.1145/3158644
[^3]: http://www.linfo.org/kernel.html
[^4]: Fournier, Q., Aloise, D., Azhari, S.V., & Tetreault, F. (2021). On Improving Deep Learning Trace Analysis with System Call Arguments. 2021 IEEE/ACM 18th International Conference on Mining Software Repositories (MSR), 120-130.
[^5]: Jamsek, D. A. (2009). Designing and optimizing compute kernels on NVIDIA GPUs. 2009 Asia and South Pacific Design Automation Conference, 224–229. doi:10.1109/ASPDAC.2009.4796484