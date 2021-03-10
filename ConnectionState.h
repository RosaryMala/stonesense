#include <memory>
#include <stdint.h>

#include "RemoteFortressReader.pb.h"
#include "RemoteClient.h"

class ConnectionState {
public:
    bool is_connected;
    RemoteFortressReader::MaterialList net_material_list;
    RemoteFortressReader::BlockList net_block_list;
    RemoteFortressReader::BlockRequest net_block_request;
    dfproto::EmptyMessage empty_message;
    DFHack::RemoteFunction<dfproto::EmptyMessage, RemoteFortressReader::MaterialList> MaterialListCall;
    DFHack::RemoteFunction<RemoteFortressReader::BlockRequest, RemoteFortressReader::BlockList> BlockListCall;

    ConnectionState();
    ~ConnectionState();

    static ConnectionState* Connect();
    static void Disconnect();

private:
    std::unique_ptr<DFHack::color_ostream> df_network_out;
    std::unique_ptr<DFHack::RemoteClient> network_client;

    static std::unique_ptr<ConnectionState> connection_state;
};
