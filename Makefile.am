# http://www.apache.org/licenses/LICENSE-2.0.txt
#
#
# Copyright 2016 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
SUBDIRS = src

.PHONY: lint deps test test-small test-medium test-large

lint:
	git ls-files '*.cc' '*.h' | grep -v pb | xargs cpplint --filter -build/c++11,-build/include_order,-build/include_subdir

test: deps
	bash -c "./scripts/test.sh $(TEST_TYPE)"
test-legacy: deps
	bash -c "./scripts/test.sh legacy"
test-small: deps
	bash -c "./scripts/test.sh small"
test-medium: deps
	bash -c "./scripts/test.sh medium"
test-large: deps
	bash -c "./scripts/test.sh large"
deps:
	bash -c "./scripts/deps.sh"

