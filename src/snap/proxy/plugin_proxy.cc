/*
http://www.apache.org/licenses/LICENSE-2.0.txt
Copyright 2016 Intel Corporation
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "snap/proxy/plugin_proxy.h"

#include <grpc++/grpc++.h>

#include "snap/rpc/plugin.pb.h"

using grpc::Server;
using grpc::ServerContext;
using grpc::Status;

using rpc::Empty;
using rpc::ErrReply;
using rpc::KillArg;
using rpc::GetConfigPolicyReply;

using Plugin::Proxy::PluginImpl;

PluginImpl::PluginImpl(Plugin::PluginInterface* plugin) : plugin(plugin) {}

Status PluginImpl::Ping(ServerContext* context, const Empty* req,
                        ErrReply* resp) {
  return Status::OK;
}

Status PluginImpl::Kill(ServerContext* context, const KillArg* req,
                        ErrReply* resp) {
  return Status::OK;
}

Status PluginImpl::GetConfigPolicy(ServerContext* context, const Empty* req,
                                   GetConfigPolicyReply* resp) {
  *resp = plugin->get_config_policy();
  return Status::OK;
}
