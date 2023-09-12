class Solution {
public:
bool isSubsequence(string s, string t)
{
	if (s.size() == 0)
		return true;
	if (t.size() == 0)
		return false;
	size_t pos = t.rfind(s.back());
	if (pos == string::npos)
		return false;
	s.pop_back();
	return isSubsequence(s, t.substr(0, pos));
}

};