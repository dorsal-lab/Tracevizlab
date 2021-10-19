
# Using the ROCm plugin in TraceCompass for big traces (several GB)

The ROCm plugin in TraceCompass is functional for big traces. However, several advices may be followed to have an improved user experience when analyzing these kinds of traces.

This document lists these advices, some known issues and future work related to the plugin.

**Table of Contents**

1. [Improve speed when loading traces and analyzes](#improve-speed-when-loading-traces-and-analyzes)
	1. [Reduce trace size](#reduce-trace-size)
	2. [Increase heap space](#increase-heap-space)
	3. [Zoom in in the Flame Chart analysis](#zoom-in-in-the-flame-chart-analysis)
	4. [Avoid starting several analyzes in parallel](#avoid-starting-several-analyzes-in-parallel)
2. [If you have some doubts about the correct execution of indexation and analyzes](#if-you-have-some-doubts-about-the-correct-execution-of-indexation-and-analyzes)
3. [Known issues](#known-issues)
4. [Future work](#future-work)

# Improve speed when loading traces and analyzes

## Reduce trace size

* Some specific features of the plugin are related to kernel execution. The data that was collected during kernel execution is principally located in the HIP stream of the CTF trace. To improve fluidity of the analyzes, having a lighter trace is the first step. Other APIs traced by the rocprof command are HSA and KFD APIs. These are low level APIs, and in most of cases they will not be useful to improve the performances of a program running on GPU. However, these APIs generate a lot of data in the traces (if tracing with –sys-trace option, HSA events account for 75% of the trace). If you do not need to see HSA and KFD events then it will be better to not trace them, only HIP events and HCC ops events should be recorded. If you did not already trace your program you should then trace it only with –hip-trace option. If the program was already traced, then you can simply remove the HSA and KFD streams from the CTF trace after conversion. The size of the analyzed trace will be much lower and the fluidity of TraceCompass and indexing and processing times will be greatly improved.


* If you are not sure if you will use the HSA and KFD streams, you can simply create a new trace that only contains these streams. To do so, copy the metadata file and the HSA and KFD streams in a new directory. This directory is the new trace, no other operation is needed. Then you can open your first trace containing only HIP events and if you need to add HSA and/or KFD events, you can open the new trace and create a TraceCompass experiment to “merge” all the streams. It would behave like if you opened the full trace (however TraceCompass will need to index the 2 trace when opening them then also the experiment, so it may be faster to just reopen the full trace if you do not need to have analyzes specific to only HIP stream and specific to HSA stream in parallel for example).

## Increase heap space

By default, the heap space allocated to Java is 1024 MB. If you have a big trace you will need to increase this heap space. To do so you need to change the -Xmx option used by Java:
* If you have the TraceCompass standalone version, then open the tracecompass.ini file with a text editor and modify the value at the line containing “-Xmx1024m”.

* If you have the TraceCompass Eclipse plugin version, then when launching TraceCompass application, go to “Run configuration->Arguments->VM arguments”. The -Xmx option should be listed here.

If you want 8GB heap space, then replace the option with “-Xmx8192m” for example.

## Zoom in in the Flame Chart analysis

Arrows to link hipLaunchKernel calls to the kernel execution on streams and queues lines in the Flame Chart are displayed. When there are a lot of arrows on the screen, browsing in the Flame Chart may be laggy. If you know there are a lot of kernels in the trace, then you should zoom in to limit the number of arrows on the screen before browsing in the Flame Chart to have more fluidity.

## Avoid starting several analyzes in parallel

Processing the analyzes will be faster if you open them one by one. You may open several analyzes in parallel, but the processing time will not be linear, and it will require more heap space to compute them. So, before opening a new analysis, you should wait until the current one is finished being processed. Once analyzes have been processed, you can safely open them in parallel.

# If you have some doubts about the correct execution of indexation and analyzes

* Indexing and processing times for the analyzes may take some time (around 1 min per analysis for a 2GB trace). However, once the analyzes have been processed, browsing in them is quite smooth. Here is some information if you have some doubts about the indexation and processing progress :
	* The indicated progression for the indexation is not yet representative of the real progression. Indexation should finish at between 7% and 15% of the current indicated progression.
	* Progression for the analyzes is not correctly displayed. It will indicate 0% but the analyzes are being processed even if nothing is moving on the screen. You should just wait several dozens of seconds depending on the size of your trace.

* All the analysis does not take the same time being processed. After indexation, the Flame Chart may be instantly available. It may not be the case for other analyzes.

* The “Function Duration Distribution” analysis does not scale well for big traces and should not be opened for traces bigger than several hundred MB.

* Analyzes related to sections of the trace need to be processed each time a new section is selected. It concerns the “Flame Graph (Selection)” analysis for example. The bigger the section is, the longer the time for the analysis to be processed will be.

# Known issues

* Progress indicator not representing the real progress
* Scaling issue on the “Function Duration Distribution” analysis
* Flame Graph analysis not opening correctly if it was opened for another trace and the trace was closed without closing the analysis before
* Pin/upin feature not working correctly. You currently can only have one analysis opened per kind of analysis (only one Flame Chart at once even if you have 2 traces opened for example, but you can open a Flame Graph with this Flame Chart).
# Future work 
* A new trace format is being developed. It will be generated with a rocprof plugin to get a CTF trace directly at runtime (no need of conversion). The asynchronous events will be in the form of intervals in this trace format. There will be only one interval event per asynchronous event in the resulting trace. Currently there are one enter and one exit events per asynchronous event after the conversion to CTF. Also, names of functions will be mapped into ID tables. The resulting trace size will be lower with this new trace format. The analyzes will be faster.
*  A feature allowing to preprocess indexation and analyzes and store the results on disk is being developed. After the preprocessing step, opening and browsing the traces will be much faster.
* Correct indexation progress will be displayed with the future trace format
* A feature allowing to hide the arrows will be added in the future
