//
// Created by fang on 2022/8/2.
//

#include "bilibili.h"
#include "bilibili/util/http.hpp"
#include "bilibili/result/search_result.h"

namespace bilibili {

void BilibiliClient::search_video(
    const std::string &key, const std::string &search_type, unsigned int index,
    const std::string &order, const std::function<void(SearchResult)> &callback,
    const ErrorCallback &error) {
    HTTP::getResultAsync<SearchResult>(
        Api::Search,
        {{"__refresh__", "true"},
         {"_extra", ""},
         {"context", ""},
         {"page", std::to_string(index)},
         {"page_size", "20"},
         {"order", order},
         {"duration", ""},
         {"from_source", ""},
         {"from_spmid", "333.337"},
         {"platform", "pc"},
         {"device", "mac"},
         {"highlight", "1"},
         {"single_column", "0"},
         {"keyword", key},
         {"category_id", ""},
         {"search_type", search_type},
         {"dynamic_offset", "0"}},
        [callback](auto data) { callback(data); }, error);
}

void BilibiliClient::get_search_hots(
    int limit, const std::function<void(SearchHotsResultWrapper)> &callback,
    const ErrorCallback &error) {
    HTTP::getResultAsync<SearchHotsResultWrapper>(
        Api::SearchHots, {{"limit", std::to_string(limit)}},
        [callback](auto data) { callback(data); }, error);
}

}  // namespace bilibili