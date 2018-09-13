# In den Blättern des Verzeichnisbaums darf man dann ruhig 'GLOB_RECURSE'
# verwenden. Alternativ kann man hier die Quelldateien auch von Hand
# in einer Liste angeben.
#file(GLOB_RECURSE WALI_SRC *.h *.cpp)

add_library(wali # Name der Bibliothek
		STATIC # Art des Linkens (statisch oder dynamisch)
#		${WALI_SRC} # Quellcode der zur dieser Bibliothek gehören soll
		Reach.cpp
		StringSource.cpp
		Common.cpp
		SemElemPair.cpp
		KeySpace.cpp
		KeySetSource.cpp
		TotalOrderWorklist.cpp
		KeyOrderWorklist.cpp
		RankedWorklist.cpp
		ShortestPathWorklist.cpp
		SemElem.cpp
		SemElemTensor.cpp
		Exception.cpp
		Printable.cpp
		Key.cpp
		IntSource.cpp
		Markable.cpp
		WeightFactory.cpp
		KeyPairSource.cpp
		IMergeFn.cpp
		MergeFn.cpp
		MergeFnFactory.cpp
		ShortestPathSemiring.cpp
		LongestSaturatingPathSemiring.cpp
		domains/SemElemSet.cpp
		domains/RepresentativeString.cpp
		wpds/RuleFunctor.cpp
		wpds/Config.cpp
		wpds/ewpds/ERule.cpp
		wpds/ewpds/ETrans.cpp
		wpds/ewpds/EWPDS.cpp
		wpds/Rule.cpp
		wpds/fwpds/FWPDS.cpp
		wpds/fwpds/SWPDS.cpp
		wpds/fwpds/LazyTrans.cpp
		wpds/Wrapper.cpp
		wpds/DebugWPDS.cpp
		wpds/WPDS.cpp
		wpds/GenKeySource.cpp
		wfa/State.cpp
		wfa/WFA.cpp
		wfa/WFA-eclose.cpp
		wfa/WFA-path_summary.cpp
		wfa/ITrans.cpp
		wfa/Trans.cpp
		wfa/WeightMaker.cpp
		wfa/TransFunctor.cpp
		wfa/TransSet.cpp
		wfa/DeterminizeWeightGen.cpp
		wfa/epr/EPA.cpp
		wfa/epr/FunctionalWeight.cpp
		wfa/epr/FunctionalWeightMaker.cpp
		witness/WitnessExtend.cpp
		witness/WitnessWrapper.cpp
		witness/WitnessRule.cpp
		witness/Visitor.cpp
		witness/CalculatingVisitor.cpp
		witness/WitnessMergeFn.cpp
		witness/VisitorDot.cpp
		witness/WitnessTrans.cpp
		witness/VisitorPrinter.cpp
		witness/Witness.cpp
		witness/WitnessCombine.cpp
		witness/WitnessMerge.cpp
		witness/WitnessLengthWorklist.cpp
		graph/RegExp.cpp
		graph/LinkEval.cpp
		regex/Concat.cpp
		regex/Regex.cpp
		regex/Root.cpp
		regex/Star.cpp
		regex/Union.cpp
		util/StringUtils.cpp
		util/ParseArgv.cpp
		util/Timer.cpp
		util/details/Partition.cpp
		graph/Functional.cpp
		graph/Graph.cpp
		graph/IntraGraph.cpp
		graph/InterGraph.cpp
		graph/SummaryGraph.cpp
)

# Falls nötig und die Bibliothek selbst Abhangigkeiten besitzt,
# kann man dieser hiermit dazu linken. Man sollte allerdings
# soweit es geht darauf verzichten, da man ansonsten schnell in
# der 'dependency hell' landet.
# target_link_libraries(test_all
# )

set_target_properties(wali
	PROPERTIES
	LINKER_LANGUAGE CXX # Linkersprache (bei CXX also C++ findet z.B. name mangling statt)
	PREFIX "lib" # Der typische 'lib' Prefix einer Bibliothek auf Unix-Systemen
)
