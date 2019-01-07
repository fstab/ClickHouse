#pragma once

#include <Storages/MergeTree/MergeTreeReader.h>
#include <Storages/MergeTree/MergeTreeIndexes.h>
#include <Storages/MergeTree/MergeTreeDataPart.h>
#include <Storages/MergeTree/MergeTreeData.h>

namespace DB {

class MergeTreeIndexReader {
public:
    MergeTreeIndexReader(
            MergeTreeIndexPtr index,
            MergeTreeData::DataPartPtr part,
            size_t marks_count,
            const MarkRanges & all_mark_ranges);

    void seek(size_t mark);

    MergeTreeIndexGranulePtr read();

private:
    MergeTreeIndexPtr index;
    MergeTreeReader::Stream stream;
};

}