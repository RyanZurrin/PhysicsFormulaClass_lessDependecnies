# This file is configured by CMake automatically as DartConfiguration.tcl
# If you choose not to use CMake, this file may be hand configured, by
# filling in the required variables.


# Configuration directories and files
SourceDirectory: D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7
BuildDirectory: D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/build

# Where to place the cost data store
CostDataFile: 

# Site is something like machine.domain, i.e. pragmatic.crd
Site: MSI

# Build name is osname-revision-compiler, i.e. Linux-2.4.2-2smp-c++
BuildName: unknownwin-19.32.31332.0-sse2-64bit

# Subprojects
LabelsForSubprojects: 

# Submission information
SubmitURL: http://manao.inria.fr/CDash/submit.php?project=Eigen+3.3
SubmitInactivityTimeout: 

# Dashboard start time
NightlyStartTime: 00:00:00 UTC

# Commands for the build/test/submit cycle
ConfigureCommand: "E:/Program Files/CMake/bin/cmake.exe" "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7"
MakeCommand: E:/Program Files/CMake/bin/cmake.exe --build . --target buildtests --config "${CTEST_CONFIGURATION_TYPE}" --  
DefaultCTestConfigurationType: Release

# version control
UpdateVersionOnly: 

# CVS options
# Default is "-d -P -A"
CVSCommand: 
CVSUpdateOptions: 

# Subversion options
SVNCommand: 
SVNOptions: 
SVNUpdateOptions: 

# Git options
GITCommand: 
GITInitSubmodules: 
GITUpdateOptions: 
GITUpdateCustom: 

# Perforce options
P4Command: 
P4Client: 
P4Options: 
P4UpdateOptions: 
P4UpdateCustom: 

# Generic update command
UpdateCommand: 
UpdateOptions: 
UpdateType: 

# Compiler info
Compiler: E:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.32.31326/bin/Hostx64/x64/cl.exe
CompilerVersion: 19.32.31332.0

# Dynamic analysis (MemCheck)
PurifyCommand: 
ValgrindCommand: 
ValgrindCommandOptions: 
DrMemoryCommand: 
DrMemoryCommandOptions: 
CudaSanitizerCommand: 
CudaSanitizerCommandOptions: 
MemoryCheckType: 
MemoryCheckSanitizerOptions: 
MemoryCheckCommand: MEMORYCHECK_COMMAND-NOTFOUND
MemoryCheckCommandOptions: 
MemoryCheckSuppressionFile: 

# Coverage
CoverageCommand: E:/msys64/mingw64/bin/gcov.exe
CoverageExtraFlags: -l

# Testing options
# TimeOut is the amount of time in seconds to wait for processes
# to complete during testing.  After TimeOut seconds, the
# process will be summarily terminated.
# Currently set to 25 minutes
TimeOut: 1500

# During parallel testing CTest will not start a new test if doing
# so would cause the system load to exceed this value.
TestLoad: 

UseLaunchers: 0
CurlOptions: 
# warning, if you add new options here that have to do with submit,
# you have to update cmCTestSubmitCommand.cxx

# For CTest submissions that timeout, these options
# specify behavior for retrying the submission
CTestSubmitRetryDelay: 5
CTestSubmitRetryCount: 3
