template<typename T>
class TSingleton {
public:
    static T &GetInstance() {
        static T ms_pInstance;
        return ms_pInstance;
    }

private:
    TSingleton() {}

    TSingleton(const TSingleton &);
    TSingleton &operator=(const TSingleton &);

protected:
    ~TSingleton() {}
};