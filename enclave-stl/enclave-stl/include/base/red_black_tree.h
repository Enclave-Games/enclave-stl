#ifndef ENCLAVED_STL_RED_BLACK_TREE
#define ENCLAVED_STL_RED_BLACK_TREE

namespace estl
{
	enum rb_tree_color
	{
		RB_TREE_COLOR_RED,
		RB_TREE_COLOR_BLACK
	};

	enum rb_tree_side
	{
		RB_TREE_SIDE_LEFT,
		RB_TREE_SIDE_RIGHT
	};

	struct rbtree_node_base
	{
		using this_type = rbtree_node_base;

	public:
		this_type* mpNodeRight;
		this_type* mpNodeLeft;
		this_type* mpNodeParent;
		char mColor;
	};

	template <typename Value>
	struct rbtree_node : public rbtree_node_base
	{
		Value mValue;

		rbtree_node(const rbtree_node&) = delete;
	};

	class rb_tree
	{
	public:

	private:

	};
}

#endif