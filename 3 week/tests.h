#pragma once

#include "test_runner.h"
#include "synonyms.h"

void TestAddSynonyms();
void TestAreSynonyms();
void TestCount();
void TestAll();

void TestAddSynonyms() {
	{
		Synonyms empty;
		AddSynomyns(empty, "a", "b");
		const Synonyms expected = {
			{"a", {"b"}},
			{"b", {"a"}}
		};
		AssertEqual(empty, expected, "Empty");
	}
	{
		Synonyms synonyms = {
			{"a", {"b"}},
			{"b", {"a", "c"}},
			{"c", {"b"}}
		};
		AddSynomyns(synonyms, "a", "c");
		const Synonyms expected = {
			{"a", {"b", "c"}},
			{"b", {"a", "c"}},
			{"c", {"b", "a"}}
		};
		AssertEqual(synonyms, expected, "Nonempty");
	}
}

void TestCount() {
	{
		Synonyms empty;
		AssertEqual(GetSynonymCount(empty, "a"),0u,"");
	}
	{
		Synonyms synonyms = {
			{"a", {"b", "c"}},
			{"b", {"a"}},
			{"c", {"a"}}
		};
		AssertEqual(GetSynonymCount(synonyms, "a"), 2u, "");
		AssertEqual(GetSynonymCount(synonyms, "b"), 1u, "");
		AssertEqual(GetSynonymCount(synonyms, "z"), 0u, "");
	}											  
	cout << "TestCount OK" << endl;
}

void TestAreSynonyms() {
	{
		Synonyms empty;
		Assert(!AreSynonyms(empty, "a", "b"),"");
		Assert(!AreSynonyms(empty, "b", "a"),"");
	}
	{
		Synonyms synonyms = {
			{"a", {"b", "c"}},
			{"b", {"a"}},
			{"c", {"a"}}
		};
		Assert(AreSynonyms(synonyms, "a", "b"),"");
		Assert(AreSynonyms(synonyms, "b", "a"),"");
		Assert(AreSynonyms(synonyms, "a", "c"),"");
		Assert(AreSynonyms(synonyms, "c", "a"),"");
		Assert(!AreSynonyms(synonyms, "b", "c"),"");
		Assert(!AreSynonyms(synonyms, "c", "b"),"");
	}
	cout << "TestAreSynonyms OK" << endl;
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestCount,"");
	tr.RunTest(TestAddSynonyms,"");
	tr.RunTest(TestAreSynonyms,"");
}