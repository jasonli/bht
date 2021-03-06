#ifndef BHT_TBBHANDLER_H__
#define BHT_TBBHANDLER_H__

#include "Common.h"
#include "InternalKey.h"
#include "Node.h"
#include "gen-cpp/BHT.h"

BHT_CODE_BEGIN

class TBBHandler:virtual public BHTIf {
public:
	TBBHandler();
	~TBBHandler();

	// 单键操作
	void Del(const ::std::string &domain, const Key &k, const bool overwrite, const bool relay);
	void Get(Val &v, const ::std::string &domain, const Key &k);
	void Set(const ::std::string &domain, const Key &k, const Val &v, const bool overwrite, const bool relay);

	// 多键操作
	void MDel(const ::std::string &domain, const ::std::vector<Key> &ks, const bool overwrite, const bool relay);
	void MGet(::std::map<Key, Val> &kvs, const ::std::string &domain, const ::std::vector<Key> &ks);
	void MSet(const ::std::string &domain, const ::std::map<Key, Val> &kvs, const bool overwrite, const bool relay);

	void UpdateConfig();

private:
	void cleanupRing(const PartitionKey &pkey, const ::std::string &s_id);
	::boost::shared_ptr<Node> locateNode(const PartitionKey &pkey);
	::boost::shared_ptr<Node> locateNodeOrInit(const PartitionKey &pkey);
};

BHT_CODE_END

#endif

